#ifndef APPLICANT_H
#define APPLICANT_H

#include <QObject>

#include "freezer.h"
#include "microwave.h"
#include "toaster.h"

class applicant : public QObject, public freezer, public toaster, public microwave
{
    Q_OBJECT
public:
    explicit applicant(QObject *parent = nullptr);

signals:


    // microwave interface
public:
    bool cook();

    // toaster interface
public:
    bool grill();

    // freezer interface
public:
    bool freeze();
};

#endif // APPLICANT_H
