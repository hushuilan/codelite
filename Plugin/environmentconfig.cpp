#include "wx/utils.h"
#include "wx/regex.h"
#include "wx/filename.h"
#include "environmentconfig.h"
#include "evnvarlist.h"
EnvironmentConfig* EnvironmentConfig::ms_instance = 0;

//------------------------------------------------------------------------------

EnvironmentConfig::EnvironmentConfig()
{
}

EnvironmentConfig::~EnvironmentConfig()
{
}

EnvironmentConfig* EnvironmentConfig::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new EnvironmentConfig();
	}
	return ms_instance;
}

void EnvironmentConfig::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

wxString EnvironmentConfig::GetRootName()
{
	return wxT("EnvironmentVariables");
}

bool EnvironmentConfig::Load()
{
	return ConfigurationToolBase::Load( wxT("config/environment_variables.xml") );
}

wxString EnvironmentConfig::ExpandVariables(const wxString &in)
{
	static wxRegEx reVarPattern(wxT("\\$\\(( *)([a-zA-Z0-9_]+)( *)\\)"));
	wxString result(in);
	
	ApplyEnv();
	
	EvnVarList vars;
	ReadObject(wxT("Variables"), &vars);
	StringMap variables = vars.GetVariables();

	while (reVarPattern.Matches(result)) {
		wxString varName = reVarPattern.GetMatch(result, 2);
		wxString text = reVarPattern.GetMatch(result);

		//search for workspace variable with this name
		wxString replacement;
		wxGetEnv(varName, &replacement);
		
		result.Replace(text, replacement);
	}
	
	UnApplyEnv();
	
	return result;
}

void EnvironmentConfig::ApplyEnv()
{
	//read the environments variables
	EvnVarList vars;
	ReadObject(wxT("Variables"), &vars);
	StringMap variables = vars.GetVariables();
	
	StringMap::iterator iter = variables.begin();
	m_envSnapshot.clear();
	for ( ; iter != variables.end(); iter++ ) {
		wxString key = iter->first;
		wxString val = iter->second;
		
		//keep old value before changing it
		wxString oldVal(wxEmptyString);
		wxGetEnv(key, &oldVal);
		m_envSnapshot[key] = oldVal;
		
		//set the new value
		wxSetEnv(key, val);
	}
}

void EnvironmentConfig::UnApplyEnv()
{
	//loop over the old values and restore them
	StringMap::iterator iter = m_envSnapshot.begin();
	for ( ; iter != m_envSnapshot.end(); iter++ ) {
		wxString key = iter->first;
		wxString value = iter->second;
		
		wxSetEnv(key, value);
	}
	m_envSnapshot.clear();
}
