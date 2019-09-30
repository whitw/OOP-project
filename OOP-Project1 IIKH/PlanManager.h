#pragma once
#include <vector>
#include "Date.h"
using namespace std;

/*****************************
  Plan Manager class manages Dates.
  It just works like DateDB.
*****************************/
class PlanManager {
	vector<Date*> dates;
public:
	PlanManager();
	PlanManager(Date* dates[]);
	~PlanManager();

	Date* find_date(int year, int month, int day);
	vector<Date*> find_dates(int yearBegin, int yearEnd, int monthBegin, int monthEnd, int dayBegin, int dayEnd);
	Date* find_plan(Plan plan);
	Date* find_plan(string title);//by title
};