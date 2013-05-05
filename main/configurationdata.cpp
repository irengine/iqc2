#include "configurationdata.h"

const QString ConfigurationData::CONFIGURATION_FILE_NAME = QString(QString("conf/utility.ini"));

ConfigurationData::ConfigurationData()
    : m_setting(CONFIGURATION_FILE_NAME, QSettings::IniFormat)
{
}

void ConfigurationData::setValue(const QString &key, const QVariant &value)
{
    m_setting.setValue(key, value);
}

QVariant ConfigurationData::getValue(const QString &key, const QVariant &defaultValue) const
{
    return m_setting.value(key, defaultValue);
}
