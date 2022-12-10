#include <iostream>
#include <algorithm>
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationService.h"
#include "GraduationServiceImpl.h"
#include "SettlementStatistics.h"
#include "SettlementStatisticImpl.h"


string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

int main() {
    // ADMIN
    /*GraduationDao *dao = new GraduationDaoImpl();
    dao->enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao->numEnrolled() << endl;

    for (int i = 0; i < numSubjects; ++i) {
        dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao->computeAverage();

*//*    cout << "Subject's averages: " << endl;
    try {
        for (int i = 0; i < numSubjects; ++i) {
            cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
        }
    }catch( domain_error& e){
        cerr << e.what() << endl;
    }*//*
    GraduationService * servicce = new GraduationServiceImpl(dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        cout << "Student id=" << id << " results: " << endl;
        try {
            auto results = servicce->findById(id);
            for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
                cout << "\t" << e.first << " : " << e.second << endl;
            });
        } catch (out_of_range &e) {
            cerr << "ID Not found Exception" << endl;
        }
    }

    delete dao;*/

    SettlementStatistics* statistics = new SettlementStatisticImpl("telepulesek.csv");

    cout<< "Num Settlements: " << statistics->numSettlements()<<'\n';
    cout<< "Num County: " << statistics->numCounties()<<'\n';
    cout<< "Num Settlements in AB County: " << statistics->numSettlementsByCounty("AB")<<'\n';\
    vector<Settlement> sett = statistics->findSettlementsByCounty("AB");
    cout<< "All Settlements in AB County:\n";
    int i = 0;
    for (auto item : sett){
        i++;
        cout<<"\t"<<i<<" "<<item<<"\n";
    }
    cout<< "Drambar AB : "<< statistics->findSettlementsByNameAndCounty("Drambar","AB")<<'\n';
    cout<< "Max Populaation: "<<statistics->maxPopulationDensity()<<'\n';
    cout<< "Min Populaation: "<<statistics->minPopulationDensity()<<'\n';
    cout<< "All Settlements named Targu Mures:\n";
    auto n = statistics->findSettlementsByName("Targu Mures");
    i = 0;
    for (auto item : n){
        i++;
        cout<<"\t"<<i<<" "<<item<<"\n";
    }

    delete statistics;

    return 0;
}