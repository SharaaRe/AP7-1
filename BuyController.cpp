#include "BuyController.h"

#include "FilmService.h"
#include "Film.h"
#include "Exceptions.h"
#include "Publisher.h"
#include "Utils.h"

#define FILM_ID "film_id"

// using service::Request;
// using service::Response;

service::Response BuyController::post(service::Request* request)
{
    current_request = request;
    check_post_params();
    FilmService film_service;
    film_service.buy(film_id);

    return service::Response(SUCCESSFUL, OK);
}

void BuyController::check_post_params()
{
    try
    {
        film_id = Utils::string_integer_value(current_request->get_request_param(FILM_ID));
    }
    catch(NotFound& er)
    {
        throw BadRequest("required params do not exist");
    }
}