#ifndef CONFIGURATIONDATA_H
#define CONFIGURATIONDATA_H

#include <QString>
#include <QVariant>
#include <QSettings>

class ConfigurationData
{
public:
    ConfigurationData();
    void setValue(const QString &key, const QVariant &value);
    QVariant getValue(const QString &key, const QVariant &defaultValue) const;

private:
    static const QString CONFIGURATION_FILE_NAME;
    QSettings m_setting;
};

#endif
