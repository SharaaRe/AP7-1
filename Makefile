

ifdef DEBUG
	CC = g++ -g -DDEBUG -std=c++11
else
	CC = g++ -g -I$(INCLUDE_DIR) -std=c++11
endif

BUILD_DIR=build/
INCLUDE_DIR=headers

OBJECTS = \
		$(BUILD_DIR)main.o \
		$(BUILD_DIR)Utils.o \
		$(BUILD_DIR)md5.o \
		$(BUILD_DIR)Exceptions.o \
		$(BUILD_DIR)RequestReciever.o \
		$(BUILD_DIR)Request.o \
		$(BUILD_DIR)Response.o \
		$(BUILD_DIR)DataBase.o \
		$(BUILD_DIR)UserSessionManagement.o \
		$(BUILD_DIR)Controller.o \
		$(BUILD_DIR)ControllerManager.o \
		$(BUILD_DIR)SignupController.o \
		$(BUILD_DIR)LoginController.o \
		$(BUILD_DIR)LogoutController.o \
		$(BUILD_DIR)FilmController.o \
		$(BUILD_DIR)FollowerController.o \
		$(BUILD_DIR)MoneyController.o \
		$(BUILD_DIR)BuyController.o \
		$(BUILD_DIR)RateController.o \
		$(BUILD_DIR)RepliesController.o \
		$(BUILD_DIR)CommentsController.o \
		$(BUILD_DIR)PurchasedController.o \
		$(BUILD_DIR)PublishedController.o \
		$(BUILD_DIR)FilmFilterController.o\
		$(BUILD_DIR)NotificationsController.o \
		$(BUILD_DIR)NotificationsReadController.o \
		$(BUILD_DIR)PutFilmsController.o \
		$(BUILD_DIR)DeleteFilmsController.o \
		$(BUILD_DIR)DeleteCommentsController.o \
		$(BUILD_DIR)LoginHandler.o \
		$(BUILD_DIR)SignupHandler.o \
		$(BUILD_DIR)LogoutHandler.o \
		$(BUILD_DIR)HomePageHandler.o \
		$(BUILD_DIR)AddFilmHandler.o \
		$(BUILD_DIR)DeleteFilmsHandler.o \
		$(BUILD_DIR)PageHandlers.o \
		$(BUILD_DIR)ProfileHandler.o \
		$(BUILD_DIR)FilmDetailHandler.o \
		$(BUILD_DIR)RateHandler.o \
		$(BUILD_DIR)BuyHandler.o \
		$(BUILD_DIR)MoneyHandler.o \
		$(BUILD_DIR)UserService.o \
		$(BUILD_DIR)FilmService.o \
		$(BUILD_DIR)FilmFilterService.o \
		$(BUILD_DIR)RecommendationService.o \
		$(BUILD_DIR)User.o \
		$(BUILD_DIR)Client.o \
		$(BUILD_DIR)Publisher.o \
		$(BUILD_DIR)Film.o \
		$(BUILD_DIR)Comment.o \
		$(BUILD_DIR)UTflixService.o \
		$(BUILD_DIR)ServerManager.o \
		$(BUILD_DIR)UTflix.o \
		$(BUILD_DIR)APHTTP.o \

mainSensitivityList = \
		main.cpp \
		$(INCLUDE_DIR)/ServerManager.h \
		$(INCLUDE_DIR)/SignupHandler.h \
		$(INCLUDE_DIR)/LoginHandler.h \
		$(INCLUDE_DIR)/server.hpp \

UtilsSensitivityList = \
		Utils.cpp \
		$(INCLUDE_DIR)/Utils.h \

md5SensivityList = \
		md5.cpp \
		$(INCLUDE_DIR)/md5.h \

ExceptionsSensivityList = \
		Exceptions.cpp \
		$(INCLUDE_DIR)/Exceptions.h \

RequestRecieverSensitivityList = \
		RequestReciever.cpp \
		$(INCLUDE_DIR)/RequestReciever.h \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/Utils.h \

RequestSensivityList = \
		Request.cpp \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Exceptions.h \

ResponseSensivityList = \
		Response.cpp \
		$(INCLUDE_DIR)/Response.h \

DataBaseSensivityList = \
		DataBase.cpp \
		$(INCLUDE_DIR)/DataBase.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/Film.h \


UserSessionManagementSensivityList = \
		UserSessionManagement.cpp \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/DataBase.h \

ControllerSensivityList = \
		Controller.cpp \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Response.h \
		$(INCLUDE_DIR)/Exceptions.h \


ControllerManagerSensivityList = \
		ControllerManager.cpp \
		$(INCLUDE_DIR)/ControllerManager.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/SignupController.h \
		$(INCLUDE_DIR)/LoginController.h \
		$(INCLUDE_DIR)/LogoutController.h \
		$(INCLUDE_DIR)/FilmController.h \
		$(INCLUDE_DIR)/FollowerController.h \
		$(INCLUDE_DIR)/MoneyController.h \
		$(INCLUDE_DIR)/BuyController.h \
		$(INCLUDE_DIR)/RateController.h \
		$(INCLUDE_DIR)/RepliesController.h \
		$(INCLUDE_DIR)/CommentsController.h \
		$(INCLUDE_DIR)/PurchasedController.h \
		$(INCLUDE_DIR)/PublishedController.h \
		$(INCLUDE_DIR)/FilmFilterController.h \
		$(INCLUDE_DIR)/NotificationsController.h \
		$(INCLUDE_DIR)/NotificationsReadController.h \
		$(INCLUDE_DIR)/PutFilmsController.h \
		$(INCLUDE_DIR)/DeleteFilmsController.h \
		$(INCLUDE_DIR)/DeleteCommentsController.h \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Response.h \
		$(INCLUDE_DIR)/Exceptions.h \




SignupControllerSensivityList = \
		SignupController.cpp \
		$(INCLUDE_DIR)/SignupController.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h\
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/Publisher.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/md5.h \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Response.h\
		$(INCLUDE_DIR)/Request.h \



LoginControllerSensivityList = \
		LoginController.cpp \
		$(INCLUDE_DIR)/LoginController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Response.h \

FilmControllerSensivityList = \
		FilmController.cpp \
		$(INCLUDE_DIR)/FilmController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/RecommendationService.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/Film.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Response.h \
		$(INCLUDE_DIR)/DataBase.h \
		$(INCLUDE_DIR)/Comment.h \


FollowerControllerSensivityList = \
		FollowerController.cpp \
		$(INCLUDE_DIR)/FollowerController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/Film.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Publisher.h \
		$(INCLUDE_DIR)/Client.h \

MoneyControllerSensivityList = \
		MoneyController.cpp \
		$(INCLUDE_DIR)/MoneyController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/Publisher.h \

BuyControllerSensivityList = \
		BuyController.cpp \
		$(INCLUDE_DIR)/BuyController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/UTflix.h \
		$(INCLUDE_DIR)/Publisher.h \


RateControllerSensivityList = \
		RateController.cpp \
		$(INCLUDE_DIR)/RateController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \



RepliesControllerSensivityList = \
		RepliesController.cpp \
		$(INCLUDE_DIR)/RepliesController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \


CommentsControllerSensivityList = \
		CommentsController.cpp \
		$(INCLUDE_DIR)/CommentsController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \

PurchasedControllerSensivityList = \
		PurchasedController.cpp \
		$(INCLUDE_DIR)/FilmFilterController.h \
		$(INCLUDE_DIR)/FilmFilterService.h \

PublishedControllerSensivityList = \
		PublishedController.cpp \
		$(INCLUDE_DIR)/FilmFilterController.h \
		$(INCLUDE_DIR)/FilmFilterService.h \

FilmFilterControllerSensivityList = \
		FilmFilterController.cpp \
		$(INCLUDE_DIR)/FilmFilterController.h \
		$(INCLUDE_DIR)/FilmFilterService.h \




NotificationsControllerSensivityList = \
		NotificationsController.cpp \
		$(INCLUDE_DIR)/NotificationsController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \


NotificationsReadControllerSensivityList = \
		NotificationsReadController.cpp \
		$(INCLUDE_DIR)/NotificationsReadController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \

PutFilmsControllerSensivityList = \
		PutFilmsController.cpp \
		$(INCLUDE_DIR)/PutFilmsController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/FilmController.h \

DeleteFilmsControllerSensivityList = \
		DeleteFilmsController.cpp \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/FilmController.h \

DeleteCommentsControllerSensivityList = \
		DeleteCommentsController.cpp \
		$(INCLUDE_DIR)/DeleteCommentsController.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/Controller.h \
		$(INCLUDE_DIR)/CommentsController.h \




# Handler sensivity lists starts from here.
# 
# 
# 

LoginHandlerSensivityList = \
		LoginHandler.cpp \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/UserService.h \
 		$(INCLUDE_DIR)/server.hpp\

SignupHandlerSensivityList = \
		SignupHandler.cpp \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/server.hpp\

LogoutHandlerSensivityList = \
		LogoutHandler.cpp \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/server.hpp\

HomePageHandlerSensivityList = \
		HomePageHandler.cpp \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/server.hpp\


AddFilmHandlerSensivityList = \
		AddFilmHandler.cpp \
		$(INCLUDE_DIR)/Utils.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
		APHTTP/static/mine/PublisherHomePage.html \


DeleteFilmsHanerSensivityList = \
		DeleteFilmsHandler.cpp \
		$(INCLUDE_DIR)/DeleteFilmsHandler.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
		APHTTP/static/mine/PublisherHomePage.html \

PageHandlersSensivityList = \
		PageHandlers.cpp \
		$(INCLUDE_DIR)/PageHandlers.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
		APHTTP/static/mine/PublisherHomePage.html \

ProfileHandlerSensivityList = \
		ProfileHandler.cpp \
		$(INCLUDE_DIR)/ProfileHandler.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
		APHTTP/static/mine/profile.html \

FilmDetailHandlerSensivityList = \
		FilmDetailHandler.cpp \
		$(INCLUDE_DIR)/FilmDetailHandler.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
		APHTTP/static/mine/films.html \

RateHandlerSensivityList = \
		RateHandler.cpp \
		$(INCLUDE_DIR)/FilmDetailHandler.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \

BuyHandlerSensivityList = \
		BuyHandler.cpp \
		$(INCLUDE_DIR)/FilmDetailHandler.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
		APHTTP/static/mine/films.html \

MoneyHandlerSensivityList = \
		MoneyHandler.cpp \
		$(INCLUDE_DIR)/FilmDetailHandler.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/server.hpp \
				
# Services Sensivity List 
# 
# 
# 
# 




UserServiceSensivityList = \
		UserService.cpp \
		$(INCLUDE_DIR)/UserService.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/Publisher.h \
		$(INCLUDE_DIR)/md5.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/DataBase.h \

FilmServiceSensivityList = \
		FilmService.cpp \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/DataBase.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/UserSessionManagement.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/Publisher.h \
		$(INCLUDE_DIR)/Comment.h \

RecommendationServiceSensivityList = \
		RecommendationService.cpp \
		$(INCLUDE_DIR)/RecommendationService.h \
		$(INCLUDE_DIR)/DataBase.h \

UserSensivityList = \
		User.cpp \
		$(INCLUDE_DIR)/User.h \

FilmFilterServiceSensivityList = \
		FilmFilterService.cpp \
		$(INCLUDE_DIR)/FilmFilterService.h \
		$(INCLUDE_DIR)/FilmService.h \
		$(INCLUDE_DIR)/Film.h \


ClientSensivityList = \
		Client.cpp \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/Publisher.h \
		$(INCLUDE_DIR)/Film.h \


PublisherSensivityList = \
		Publisher.cpp \
		$(INCLUDE_DIR)/Publisher.h \
		$(INCLUDE_DIR)/Client.h \
		$(INCLUDE_DIR)/User.h \
		$(INCLUDE_DIR)/Film.h \
		$(INCLUDE_DIR)/Exceptions.h \


FilmSensivityList = \
		Film.cpp \
		$(INCLUDE_DIR)/Film.h \
		$(INCLUDE_DIR)/Exceptions.h \
		$(INCLUDE_DIR)/Utils.h \

CommentSensivitiyList = \
		Comment.cpp \
		$(INCLUDE_DIR)/Comment.h \

UTflixServiceSernsivityList = \
		UTflixService.cpp \
		$(INCLUDE_DIR)/RequestReciever.h \
		$(INCLUDE_DIR)/Request.h \
		$(INCLUDE_DIR)/Response.h \
		$(INCLUDE_DIR)/ControllerManager.h \
		$(INCLUDE_DIR)/Controller.h \

ServerManagerSenisivityList = \
		ServerManager.cpp \
		$(INCLUDE_DIR)/server.hpp\

UTflixSensivityList = \
		UTflix.cpp \
		$(INCLUDE_DIR)/UTflix.h \
		$(INCLUDE_DIR)/Publisher.h \
		

all: $(BUILD_DIR)UTflix.out 


$(BUILD_DIR)APHTTP.o:
	make -f APHTTP/makefile BUILD_DIR=$(BUILD_DIR) INCLUDE_DIR=$(INCLUDE_DIR)

$(BUILD_DIR)main.o: $(mainSensitivityList)
	$(CC) -c main.cpp -o $(BUILD_DIR)main.o

$(BUILD_DIR)Utils.o: $(UtilsSensitivityList)
	$(CC) -c  Utils.cpp -o $(BUILD_DIR)Utils.o

$(BUILD_DIR)md5.o: $(md5SensivityList)
	$(CC) -c  md5.cpp -o $(BUILD_DIR)md5.o

$(BUILD_DIR)Exceptions.o: $(ExceptionsSensivityList)
	$(CC) -c  Exceptions.cpp -o $(BUILD_DIR)Exceptions.o

$(BUILD_DIR)RequestReciever.o: $(RequestRecieverSensitivityList)
	$(CC) -c  RequestReciever.cpp -o $(BUILD_DIR)RequestReciever.o

$(BUILD_DIR)Request.o: $(RequestSensivityList)
	$(CC) -c  Request.cpp -o $(BUILD_DIR)Request.o

$(BUILD_DIR)Response.o: $(ResponseSensivityList)
	$(CC) -c  Response.cpp -o $(BUILD_DIR)Response.o

$(BUILD_DIR)DataBase.o: $(DataBaseSensivityList)
	$(CC) -c  DataBase.cpp -o $(BUILD_DIR)DataBase.o

$(BUILD_DIR)UserSessionManagement.o: $(UserSessionManagementSensivityList)
	$(CC) -c  UserSessionManagement.cpp -o $(BUILD_DIR)UserSessionManagement.o

$(BUILD_DIR)Controller.o: $(ControllerSensivityList)
	$(CC) -c  Controller.cpp -o $(BUILD_DIR)Controller.o

$(BUILD_DIR)ControllerManager.o: $(ControllerManagerSensivityList)
	$(CC) -c  ControllerManager.cpp -o $(BUILD_DIR)ControllerManager.o

$(BUILD_DIR)SignupController.o: $(SignupControllerSensivityList)
	$(CC) -c  SignupController.cpp -o $(BUILD_DIR)SignupController.o

$(BUILD_DIR)LoginController.o: $(LoginControllerSensivityList)
	$(CC) -c  LoginController.cpp -o $(BUILD_DIR)LoginController.o

$(BUILD_DIR)LogoutController.o: $(LogoutControllerSensivityList)
	$(CC) -c  LogoutController.cpp -o $(BUILD_DIR)LogoutController.o

$(BUILD_DIR)FilmController.o: $(FilmControllerSensivityList)
	$(CC) -c FilmController.cpp -o $(BUILD_DIR)FilmController.o

$(BUILD_DIR)FollowerController.o: $(FollowerController)
	$(CC) -c FollowerController.cpp -o $(BUILD_DIR)FollowerController.o

$(BUILD_DIR)MoneyController.o: $(MoneyControllerSensivityList)
	$(CC) -c MoneyController.cpp -o $(BUILD_DIR)MoneyController.o

$(BUILD_DIR)BuyController.o: $(BuyControllerSensivityList)
	$(CC) -c BuyController.cpp -o $(BUILD_DIR)BuyController.o

$(BUILD_DIR)RateController.o: $(RateControllerSensivityList)
	$(CC) -c RateController.cpp -o $(BUILD_DIR)RateController.o

$(BUILD_DIR)RepliesController.o: $(RepliesControllerSensivityList)
	$(CC) -c RepliesController.cpp -o $(BUILD_DIR)RepliesController.o

$(BUILD_DIR)CommentsController.o: $(CommentsControllerSensivityList)
	$(CC) -c CommentsController.cpp -o $(BUILD_DIR)CommentsController.o

$(BUILD_DIR)PublishedController.o: $(PublishedControllerSensivityList)
	$(CC) -c PublishedController.cpp -o $(BUILD_DIR)PublishedController.o

$(BUILD_DIR)FilmFilterController.o: $(FilmFilterControllerSensivityList)
	$(CC) -c FilmFilterController.cpp -o $(BUILD_DIR)FilmFilterController.o

$(BUILD_DIR)PurchasedController.o: $(PurchasedControllerSensivityList)
	$(CC) -c PurchasedController.cpp -o $(BUILD_DIR)PurchasedController.o

$(BUILD_DIR)NotificationsController.o: $(NotificationsSensivityList)
	$(CC) -c NotificationsController.cpp -o $(BUILD_DIR)NotificationsController.o

$(BUILD_DIR)NotificationsReadController.o: $(NotificationsReadControllerSensivityList)
	$(CC) -c NotificationsReadController.cpp -o $(BUILD_DIR)NotificationsReadController.o


$(BUILD_DIR)PutFilmsController.o: $(PublishedControllerSensivityList) 
	$(CC) -c PutFilmsController.cpp -o $(BUILD_DIR)PutFilmsController.o

$(BUILD_DIR)DeleteFilmsController.o: $(DeleteCommentsControllerSensivityList) 
	$(CC) -c DeleteFilmsController.cpp -o $(BUILD_DIR)DeleteFilmsController.o

$(BUILD_DIR)DeleteCommentsController.o: $(DeleteCommentsControllerSensivityList) 
	$(CC) -c DeleteCommentsController.cpp -o $(BUILD_DIR)DeleteCommentsController.o


# Handler builders

$(BUILD_DIR)SignupHandler.o: $(SignupHandlerSensivityList)
	$(CC) -c SignupHandler.cpp -o $(BUILD_DIR)SignupHandler.o

$(BUILD_DIR)LoginHandler.o: $(LoginHandlerSensivityList)
	$(CC) -c LoginHandler.cpp -o $(BUILD_DIR)LoginHandler.o

$(BUILD_DIR)LogoutHandler.o: $(LogoutHandlerSensivityList)
	$(CC) -c LogoutHandler.cpp -o $(BUILD_DIR)LogoutHandler.o

$(BUILD_DIR)HomePageHandler.o: $(HomePageHandlerSensivityList)
	$(CC) -c HomePageHandler.cpp  -o $(BUILD_DIR)HomePageHandler.o

$(BUILD_DIR)AddFilmHandler.o: $(AddFilmHandlerSensivityList)
	$(CC) -c AddFilmHandler.cpp -o $(BUILD_DIR)AddFilmHandler.o

$(BUILD_DIR)DeleteFilmsHandler.o: $(DeleteFilmsHandlerSensivityList)
	$(CC) -c DeleteFilmsHandler.cpp -o 	$(BUILD_DIR)DeleteFilmsHandler.o

$(BUILD_DIR)PageHandlers.o: $(PageHandlersSensivityList)
	$(CC) -c PageHandlers.cpp -o $(BUILD_DIR)PageHandlers.o

$(BUILD_DIR)ProfileHandler.o: $(ProfileHandlerSensivityList)
	$(CC) -c ProfileHandler.cpp -o $(BUILD_DIR)ProfileHandler.o

$(BUILD_DIR)FilmDetailHandler.o: $(FilmDetailHandlerSensivityList)
	$(CC) -c FilmDetailHandler.cpp -o $(BUILD_DIR)FilmDetailHandler.o

$(BUILD_DIR)RateHandler.o: $(RateHandlerSensivityList)
	$(CC) -c RateHandler.cpp -o $(BUILD_DIR)RateHandler.o

$(BUILD_DIR)BuyHandler.o: $(BuyHandlerSensivityList)
	$(CC) -c BuyHandler.cpp -o $(BUILD_DIR)BuyHandler.o

$(BUILD_DIR)MoneyHandler.o: $(MoneyHandlerSensivityList)
	$(CC) -c MoneyHandler.cpp -o $(BUILD_DIR)MoneyHandler.o
# 

$(BUILD_DIR)UserService.o: $(UserServiceSensivityList)
	$(CC) -c  UserService.cpp -o $(BUILD_DIR)UserService.o

$(BUILD_DIR)FilmService.o: $(FilmServiceSensivityList)
	$(CC) -c FilmService.cpp -o $(BUILD_DIR)FilmService.o

$(BUILD_DIR)FilmFilterService.o: $(FilmFilterServiceSensivityList)
	$(CC) -c FilmFilterService.cpp -o $(BUILD_DIR)FilmFilterService.o

$(BUILD_DIR)RecommendationService.o: $(RecommendationServiceSensivityList)
	$(CC) -c RecommendationService.cpp -o $(BUILD_DIR)RecommendationService.o

$(BUILD_DIR)User.o: $(UserSensivityList)
	$(CC) -c  User.cpp -o $(BUILD_DIR)User.o

$(BUILD_DIR)Client.o: $(ClientSensivityList)
	$(CC) -c  Client.cpp -o $(BUILD_DIR)Client.o

$(BUILD_DIR)Publisher.o: $(PublisherSensivityList)
	$(CC) -c  Publisher.cpp -o $(BUILD_DIR)Publisher.o

$(BUILD_DIR)Film.o: $(FilmSensivityList)
	$(CC) -c  Film.cpp -o $(BUILD_DIR)Film.o

$(BUILD_DIR)Comment.o: $(CommentSensivitiyList)
	$(CC) -c  Comment.cpp -o $(BUILD_DIR)Comment.o

$(BUILD_DIR)UTflixService.o: $(UTflixServiceSernsivityList)
	$(CC) -c UTflixService.cpp -o $(BUILD_DIR)UTflixService.o


$(BUILD_DIR)UTflix.o: $(UTflixSensivityList)
	$(CC) -c UTflix.cpp -o $(BUILD_DIR)UTflix.o

$(BUILD_DIR)ServerManager.o: $(ServerManagerSenisivityList)
	$(CC) -c ServerManager.cpp -o $(BUILD_DIR)ServerManager.o

$(BUILD_DIR)UTflix.out: $(OBJECTS)
	$(CC) -o UTflix.out $(OBJECTS) -o APHTTP/build/UTflix.out

.PHONY: clean

clean:
	rm $(BUILD_DIR)*.o
	rm UTflix.out