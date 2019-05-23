#include "FilmFilterService.h"

#include <algorithm>

using namespace std;

void FilmFilterService::filter_by_name(string name)
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_name() == name)
            filtered.push_back(films[i]);
    }

    films = filtered;
}  

void FilmFilterService::filter_by_director(string director)
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_director() == director)
            filtered.push_back(films[i]);
    }

    films = filtered;
}   

void FilmFilterService::filter_by_max_year(int max_year)
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_year() <= max_year)
            filtered.push_back(films[i]);
    }

    films = filtered;
}   

void FilmFilterService::filter_by_max_year(int min_year)
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_year() >= min_year)
            filtered.push_back(films[i]);
    }

    films = filtered;
}

void FilmFilterService::filter_by_price(int price)
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_price() == price)
            filtered.push_back(films[i]);
    }

    films = filtered;
}

void FilmFilterService::filter_by_min_rate(float min_rate)
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_rate() >= min_rate)
            filtered.push_back(films[i]);
    }

    films = filtered;
}   

void FilmFilterService::stable_sort_by_rate()
{
    stable_sort(films.begin(), films.end(), compare_by_rate);
}

void FilmFilterService::filter_purchased(vector <int> purchased_ids)
{
    vector <Film> filtered;
    for (int j = 0; j < purchased_ids.size(); j++)
    {
        for (int i = 0; i < films.size(); i++)
        {
            if (films[i].get_id() != purchased_ids[j])
                filtered.push_back(films[i]);
        }
    }

    films = filtered;  
}

void FilmFilterService::filter_not_available()
{
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].is_available())
            filtered.push_back(films[i]);
    }

    films = filtered;
}

bool FilmFilterService::compare_by_rate(Film first, Film second)
{
    return (first.get_rate() < second.get_rate());
}
