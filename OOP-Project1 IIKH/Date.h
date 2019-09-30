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
	string get_title();
	string get_contents();
};

class Date {
	int year;
	int month;
	int day;
	vector<Plan*> plan;
	vector<Meal*> meal;
public:
	Date(int year, int month, int day);
	~Date();
	
	//find plan and return the index of it.
	int findPlanIndex(Plan plan);
	int findPlanIndexByTitle(string title);
	int findPlanIndex(string title); // by title

	int findPlanIndexByContents(string contents);

	//add plan.
	bool addPlan(Plan plan);
	void replacePlan(int index, Plan plan);
	bool removePlan(int index);
	bool removePlan(Plan plan);

	
};