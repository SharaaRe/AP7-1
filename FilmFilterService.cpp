#include "FilmFilterService.h"

#include <algorithm>

using namespace std;

FilmFilterService::FilmFilterService(vector <Film> _films)
{
    films = _films;
}


void FilmFilterService::filter(string name, int max_year, int min_year,
         int price, float min_rate , string director)

{
    filter_by_name(name);
    filter_by_min_year(min_year);
    filter_by_max_year(max_year);
    filter_by_min_rate(min_rate);
    filter_by_price(price);
    filter_by_director(director);
}

void FilmFilterService::filter_by_name(string name)
{
    if (name == NOT_FILTERED_ST)
        return;

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
    if (director == NOT_FILTERED_ST)
        return;
        
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
    if (max_year == NOT_FILTERED)
        return;
            
    vector <Film> filtered;
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].get_year() <= max_year)
            filtered.push_back(films[i]);
    }

    films = filtered;
}   

void FilmFilterService::filter_by_min_year(int min_year)
{
    if (min_year == NOT_FILTERED)
        return;
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
    if (price == NOT_FILTERED)
        return;
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
    if (min_rate == NOT_FILTERED)
        return;
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

void FilmFilterService::filter_purchased(vector <Film> purchased_ids)
{
    vector <Film> filtered;
    for (int j = 0; j < purchased_ids.size(); j++)
    {
        for (int i = 0; i < films.size(); i++)
        {
            if (films[i].get_id() != purchased_ids[j].get_id())
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

vector <Film> FilmFilterService::get_filtered()
{
    return films;
}

bool FilmFilterService::compare_by_rate(Film first, Film second)
{
    return (first.get_rate() > second.get_rate());
}
