#include "PurchasedController.h"

#include "UserSessionManagement.h"

using service::Request;
using service::Response;

service::Response PurchasedController::get(service::Request* request)
{
    current_request = request;
    check_params();
    FilmFilterService film_filter(film_service.get_purchased());
    film_filter.filter(name , max_year, min_year, price, rate, director);
    films = film_filter.get_filtered();
    return make_get_film_response();
}