//
// Created by Matyas Kondert on 12/7/2022.
//

#include <algorithm>
#include "SettlementStatisticImpl.h"

int SettlementStatisticImpl::numSettlements() const
{
    return this->data.size();
}

int SettlementStatisticImpl::numCounties() const
{
    unordered_set<string> set;
    for (auto &item : this->data){
        set.insert(item.first);
    }
    return set.size();
}

int SettlementStatisticImpl::numSettlementsByCounty(const string &county) const
{
    int sz = 0;
    for (auto &item : this->data){
        if (item.first == county){
            sz++;
        }
    }
    return sz;
}

vector<Settlement> SettlementStatisticImpl::findSettlementsByCounty(const string &county) const
{
    vector<Settlement> settalments;
    for (auto &item : this->data){
        if (item.first == county){
            settalments.emplace_back(item.second);
        }
    }
    return settalments;
}

Settlement SettlementStatisticImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const
{
    auto p = find_if(data.begin(), data.end(),[name,county](pair<string,Settlement> item){
        return (name == item.second.getName() && county == item.first);
    });
    return p->second;
}

Settlement SettlementStatisticImpl::maxPopulationDensity() const
{
    auto s = max_element(data.begin(),data.end(),[](pair<string,Settlement> a, pair<string,Settlement> b){
        return a.second.getPopulation() < b.second.getPopulation();
    });
    return s->second;
}

Settlement SettlementStatisticImpl::minPopulationDensity() const
{
    auto s = min_element(data.begin(),data.end(),[](pair<string,Settlement> a, pair<string,Settlement> b){
        return a.second.getPopulation() < b.second.getPopulation();
    });
    return s->second;
}

vector<Settlement> SettlementStatisticImpl::findSettlementsByName(const string &name)
{
    vector<Settlement> settalments;
    for (auto &item : this->data){
        if (item.second.getName() == name){
            settalments.emplace_back(item.second);
        }
    }
    return settalments;
}

SettlementStatisticImpl::SettlementStatisticImpl(const string &fileName)
{
    ifstream input(fileName);
    if (!input)
    {
        cerr<<"File open Error"<<"\n";
        exit(1);
    }
    string line;
    getline(input,line);//Skip header
    while (getline(input,line)){
        istringstream ss(line);
        string name,county;
        int pop;
        getline(ss,name,',');
        getline(ss,county,',');
        ss>>pop;
        this->data.insert({county,Settlement(name,county,pop)});
    }

}
