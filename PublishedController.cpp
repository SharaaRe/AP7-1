#include "PublishedController.h"

#include "Utils.h"
#include "FilmFilterService.h"
#include "FilmService.h"

Response PublishedController::get(Request* request)
{
    current_request = request;
    check_params();
    FilmFilterService film_filter(film_service.get_published());
    film_filter.filter(name , max_year, min_year, price, rate, director);
    film_filter.filter_not_available();
    films = film_filter.get_filtered();
    return make_get_film_respnse();
}

void PublishedController::check_params()
{
    re_initialize_params();
    FilmFilterController::check_params();
    // rate = Utils:: check rate
}
