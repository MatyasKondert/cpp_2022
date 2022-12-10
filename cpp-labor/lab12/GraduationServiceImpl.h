//
// Created by Matyas Kondert on 12/7/2022.
//

#ifndef LAB12_GRADUATIONSERVICEIMPL_H
#define LAB12_GRADUATIONSERVICEIMPL_H


#include "Student.h"
#include "GraduationService.h"
#include "GraduationDao.h"

class GraduationServiceImpl : public GraduationService
{
public:
    Student findById(int id) const override;
    double getResultByIdAndSubject(int id,
                                           const string& subject) const override;
    explicit GraduationServiceImpl(GraduationDao* dao);

private:
    GraduationDao* dao;
};


#endif //LAB12_GRADUATIONSERVICEIMPL_H
