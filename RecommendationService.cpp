#include "RecommendationService.h"

#include <algorithm>

#include "DataBase.h"

#include <iostream>

#define FILM_ID_INDEX 0
#define ZERO 0
#define TRAIN_DATA -1


using namespace std;

RecommendationService* RecommendationService::instance = nullptr;

RecommendationService* RecommendationService::get_instance()
{
    if (instance == nullptr)
        instance = new RecommendationService();

    return instance;
}

RecommendationService::RecommendationService()
{
    database = DataBase::get_instance();
    films_matrix.push_back(vector<int> (1, TRAIN_DATA));
}

void RecommendationService::add_film(int id)
{
    for (int i = FILM_ID_INDEX + 1; i < films_matrix.size(); i++)
        films_matrix[i].push_back(ZERO);

    vector <int> new_row(films_matrix.size() + 1, ZERO);
    new_row[FILM_ID_INDEX] = id;
    new_row[id] = -1;

    films_matrix.push_back(new_row);
    
}

void RecommendationService::add_new_graph(int id, vector <int> related_films)
{
    for (int i = 0; i < related_films.size(); i++)
    {
        if (i != id)
        {
            int relatedd_film_index = related_films[i];
            films_matrix[relatedd_film_index][id]++;
            films_matrix[id][relatedd_film_index]++;
        }
    }
}


vector <Film> RecommendationService::recommended_films(int film_id)
{
    vector <int> rates = films_matrix[film_id];

    vector <RateIdPair> rate_row = sort_row_by_rate(film_id, rates);
    vector <Film> recoms;


    for (int i = 1; i < rate_row.size(); i++)
    {
        if (rate_row[i].first != film_id)
            recoms.push_back(*database->search_film(rate_row[i].first));
    }
    return recoms;
}

vector <RateIdPair> RecommendationService::sort_row_by_rate(int id, vector <int> rates)
{
    vector <RateIdPair> rate_row;

    for (int i = 1; i < rates.size(); i++)
    {
        RateIdPair node;
        node.first = i;
        node.second = rates[i];

        rate_row.push_back(node);
    }

    sort(rate_row.begin(), rate_row.end(), rate_compare);

    return rate_row;
}

bool RecommendationService::rate_compare(RateIdPair left, RateIdPair right)
{
    return left.second > right.second;
}