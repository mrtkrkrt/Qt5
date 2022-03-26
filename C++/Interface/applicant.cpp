#include "applicant.h"

applicant::applicant(QObject *parent)
    : QObject{parent}
{

}

bool applicant::cook()
{
    return true;
}

bool applicant::grill()
{
    return true;
}

bool applicant::freeze()
{
    return true;
}
