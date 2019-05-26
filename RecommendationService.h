#ifndef RECOMMENDATION_SERVICE_H
#define RECOMMENDATION_SERVICE_H

#include <vector>
#include <map>

#include "Film.h"

typedef std::pair <int, int> RateIdPair;



class DataBase;

typedef std::vector <std::vector <int>> AdjacencyMatrix;

class RecommendationService
{
public:
    static RecommendationService* get_instance();
    void add_film(int id);
    void delete_film(int id);
    void add_new_graph(int film_id, std::vector <int> adjacent_films_ids);
    std::vector <Film> recommended_films(int film_id);
private:
    RecommendationService();
    static bool rate_compare(RateIdPair left, RateIdPair right);
    std::vector <RateIdPair> sort_row_by_rate(int id, std::vector <int> row);
    // int find_index(int film_id);
    static RecommendationService* instance;
    DataBase* database;
    AdjacencyMatrix films_matrix;
    // std::map <int, int> index_map;
};

#endif