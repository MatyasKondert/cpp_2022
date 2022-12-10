//
// Created by Matyas Kondert on 12/7/2022.
//

#ifndef LAB12_SETTLEMENTSTATISTICIMPL_H
#define LAB12_SETTLEMENTSTATISTICIMPL_H


#include <vector>
#include <map>
#include "Settlement.h"
#include "SettlementStatistics.h"
#include <fstream>
#include <sstream>
#include <unordered_set>

class SettlementStatisticImpl : public SettlementStatistics
{
private:
    multimap<string,Settlement> data;
public:
    SettlementStatisticImpl(const string &fileName);

    int numSettlements() const override;
    int numCounties() const override;
    int numSettlementsByCounty(const string& county) const override;
    vector<Settlement> findSettlementsByCounty(const string& county) const override;
    Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;
    Settlement maxPopulationDensity() const override;
    Settlement minPopulationDensity() const override;
    vector<Settlement> findSettlementsByName(const string& name) override;
};


#endif //LAB12_SETTLEMENTSTATISTICIMPL_H
