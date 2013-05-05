#ifndef RULEINTERFACE_H
#define RULEINTERFACE_H

class RuleInterface
{
public:
    virtual ~RuleInterface() { }

    virtual void apply() = 0;
};

Q_DECLARE_INTERFACE(RuleInterface,
                    "com.taoware.iqc.RuleInterface/1.0")

#endif // RULEINTERFACE_H
