#pragma once
#include <vector>
#include <string>
#include "Meal.h"

using namespace std;
class Plan {
	string title;
	string contents;
public:
	Plan(string title, string contents);
	Plan(string title);
};

class Date {
	int year;
	int month;
	int day;
	vector<Plan> plan;
	vector<Meal> meal;
public:
	Date(int year, int month, int day);
	//add plan.
	bool addPlan(Plan plan);
	//find plan and remove it.
	int getPlan(Plan plan);
	//find plan and return the index of it.
	int findPlanIndex(Plan plan);
	int findPlanIndex(string title);
	int findPlanIndexByTitle(string title);
	int findPlanIndexByContents(string title);
	void replacePlan(int index, Plan plan);
	bool removePlan(int index);
	bool removePlan(Plan plan);
};