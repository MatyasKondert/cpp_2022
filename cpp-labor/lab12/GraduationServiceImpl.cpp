//
// Created by Matyas Kondert on 12/7/2022.
//

#include "GraduationServiceImpl.h"


GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao)
{
    this->dao = dao;
}

Student GraduationServiceImpl::findById(int id) const
{
    return dao->findById(id);
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const
{
    return 0;
}
