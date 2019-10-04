#pragma once
#include <vector>
#include <string>
#include "RecipeDB.h"
using namespace std;

/**********************
   Plan Class represents
   memo about one Plan.
   It only supports
   initializing and printing
***********************/
class Plan {
	string title;
	string contents;
public:
	Plan(string title, string contents);
	Plan(string title);
	string get_title();
	string get_contents();
};

/**************************
    Date Class represents
	one Day on diary.
	It also stores plan on that day,
	and meal to consume that day.
***************************/
class Date {
	int year;
	int month;
	int day;
	vector<Plan*> plan;
	vector<RecipeDB*> meal;
public:
	Date(int year, int month, int day);
	~Date();
	
	//find plan and return the index of it.
	int findPlanIndex(Plan plan);
	int findPlanIndexByTitle(string title);
	int findPlanIndex(string title); // by title

	int findPlanIndexByContents(string contents);

	//add/replace/remove plan.
	bool add_plan(Plan plan);
	
	//plan[index] = plan
	void replace_plan(int index, Plan plan);

	//delete plan[index]
	bool remove_plan(int index);
	bool remove_plan(Plan plan);

	//add, find, delete menu 
	void add_menu(Recipe* recipe);
	RecipeDB* get_all_menu();
	Recipe* find_menu(string title);
	void delete_menu(string title);

	int get_year();
	int get_month();
	int get_date();
};