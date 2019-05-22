#include "BuyController.h"

#include "UserSessionManagement.h"
#include "DataBase.h"
#include "Utils.h"
#include "Client.h"
#include "Film.h"
#include "Exceptions.h"
#include "Publisher.h"

#define FILM_ID "film_id"

Response BuyController::post(Request* request)
{
    Client* client = UserSessionManagement::get_instance()->get_logged_client();
    Film* film = DataBase::get_instance()->search_film(Utils::string_integer_value(request->get_request_param(FILM_ID)));
    Publisher* publisher = dynamic_cast <Publisher*> (DataBase::get_instance()->search_client(film->get_publisher_id()));
    if (film->is_available())
    {
        client->purchase_film(film);
        publisher->sell_film(film->calculate_publisher_part());
        Response(SUCCESSFUL, OK);
    }
    else
        throw NotFound("film is not available");
}