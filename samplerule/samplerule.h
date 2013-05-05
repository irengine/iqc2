#ifndef SAMPLERULE_H
#define SAMPLERULE_H

#include <QObject>
#include "../main/ruleinterface.h"

class SampleRule : public QObject, public RuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.taoware.iqc.RuleInterface" FILE "samplerule.json")
    Q_INTERFACES(RuleInterface)

public:
    void apply();
};

#endif // SAMPLERULE_H
