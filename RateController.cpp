#include "RateController.h"

#include "Utils.h"
#include "FilmService.h"
#include "Exceptions.h"

Response RateController::post(Request* request)
{
    current_request = request;
    FilmService film_service;
    film_service.rate(film_id, score);

    return Response(SUCCESSFUL, OK);
}

void RateController::check_post_params()
{
    try
    {
        film_id = Utils::string_integer_value(current_request->get_request_param(FILM_ID));
        score = Utils::string_integer_value(current_request->get_request_param(SCORE));
    }
    catch(Exception& er)
    {
        throw BadRequest("a required param doesn't exist");
    }
}