ifdef DEBUG
	CC = g++ -g -DDEBUG -std=c++11
else
	CC = g++ -g -std=c++11
endif

OBJECTS = \
		main.o \
		Utils.o \
		md5.o \
		Exceptions.o \
		RequestReciever.o \
		Request.o \
		Response.o \
		DataBase.o \
		UserSessionManagement.o \
		Controller.o \
		ControllerManager.o \
		SignupController.o \
		LoginController.o \
		FilmController.o \
		FollowerController.o \
		MoneyController.o \
		BuyController.o \
		RateController.o \
		RepliesController.o \
		CommentsController.o \
		PurchasedController.o \
		PublishedController.o \
		FilmFilterController.o\
		NotificationsController.o \
		NotificationsReadController.o \
		UserService.o \
		FilmService.o \
		FilmFilterService.o \
		User.o \
		Client.o \
		Publisher.o \
		Film.o \
		Comment.o \
		UTflix.o \

mainSensitivityList = \
		main.cpp \
		RequestReciever.h \
		Request.h \
		Response.h \
		ControllerManager.h \
		Controller.h \

UtilsSensitivityList = \
		Utils.cpp \
		Utils.h \

md5SensivityList = \
		md5.cpp \
		md5.h \

ExceptionsSensivityList = \
		Exceptions.cpp \
		Exceptions.h \

RequestRecieverSensitivityList = \
		RequestReciever.cpp \
		RequestReciever.h \
		Request.h \
		Exceptions.h \
		Utils.h \

RequestSensivityList = \
		Request.cpp \
		Request.h \
		Exceptions.h \

ResponseSensivityList = \
		Response.cpp \
		Response.h \

DataBaseSensivityList = \
		DataBase.cpp \
		DataBase.h \
		Exceptions.h \
		User.h \
		Client.h \
		Film.h \


UserSessionManagementSensivityList = \
		UserSessionManagement.cpp \
		UserSessionManagement.h \
		User.h \
		DataBase.h \

ControllerSensivityList = \
		Controller.cpp \
		Controller.h \
		Request.h \
		Response.h \
		Exceptions.h \


ControllerManagerSensivityList = \
		ControllerManager.cpp \
		ControllerManager.h \
		Controller.h \
		SignupController.h \
		LoginController.h \
		Request.h \
		Response.h \
		Exceptions.h \




SignupControllerSensivityList = \
		SignupController.cpp \
		SignupController.h \
		UserService.h \
		UserSessionManagement.h\
		Controller.h \
		User.h \
		Client.h \
		Publisher.h \
		Exceptions.h \
		md5.h \
		Utils.h \
		Response.h\
		Request.h \



LoginControllerSensivityList = \
		LoginController.cpp \
		LoginController.h \
		Controller.h \
		UserService.h \
		User.h \
		UserSessionManagement.h \
		Request.h \
		Response.h \

FilmControllerSensivityList = \
		FilmController.cpp \
		FilmController.h \
		Controller.h \
		FilmService.h \
		User.h \
		Client.h \
		Film.h \
		UserSessionManagement.h \
		Request.h \
		Response.h \
		DataBase.h \
		Comment.h \


FollowerControllerSensivityList = \
		FollowerController.cpp \
		FollowerController.h \
		Controller.h \
		UserService.h \
		Film.h \
		User.h \
		Publisher.h \
		Client.h \

MoneyControllerSensivityList = \
		MoneyController.cpp \
		MoneyController.h \
		Controller.h \
		UserSessionManagement.h \
		Client.h \
		Publisher.h \

BuyControllerSensivityList = \
		BuyController.cpp \
		BuyController.h \
		Controller.h \
		UserSessionManagement.h \
		Client.h \
		UTflix.h \
		Publisher.h \


RateControllerSensivityList = \
		RateController.cpp \
		RateController.h \
		Controller.h \
		FilmService.h \
		Utils.h \
		Exceptions.h \



RepliesControllerSensivityList = \
		RepliesController.cpp \
		RepliesController.h \
		Controller.h \
		FilmService.h \
		Utils.h \
		Exceptions.h \


CommentsControllerSensivityList = \
		CommentsController.cpp \
		CommentsController.h \
		Controller.h \
		FilmService.h \
		Utils.h \
		Exceptions.h \

PurchasedControllerSensivityList = \
		PurchasedController.cpp \
		FilmFilterController.h \
		FilmFilterService.h \

PublishedControllerSensivityList = \
		FilmFilterController.h \
		FilmFilterService.h \

FilmFilterControllerSensivityList = \
		FilmFilterController.h \
		FilmFilterService.h \




NotificationsControllerSensivityList = \
		NotificationsController.cpp \
		NotificationsController.h \
		Controller.h \
		UserService.h \
		Utils.h \
		Exceptions.h \


NotificationsReadControllerSensivityList = \
		NotificationsReadController.cpp \
		NotificationsReadController.h \
		Controller.h \
		UserService.h \
		Utils.h \
		Exceptions.h \


UserServiceSensivityList = \
		UserService.cpp \
		UserService.h \
		User.h \
		Client.h \
		Publisher.h \
		md5.h \
		Exceptions.h \
		UserSessionManagement.h \
		DataBase.h \

FilmServiceSensivityList = \
		FilmService.cpp \
		FilmService.h \
		DataBase.h \
		Exceptions.h \
		UserSessionManagement.h \
		Client.h \
		Publisher.h \
		Comment.h \


UserSensivityList = \
		User.cpp \
		User.h \

FilmFilterServiceSensivityList = \
		FilmFilterService.cpp \
		FilmFilterService.h \
		FilmService.h \
		Film.h \


ClientSensivityList = \
		Client.cpp \
		Client.h \
		User.h \
		Exceptions.h \
		Publisher.h \
		Film.h \


PublisherSensivityList = \
		Publisher.cpp \
		Publisher.h \
		Client.h \
		User.h \
		Film.h \
		Exceptions.h \


FilmSensivityList = \
		Film.cpp \
		Film.h \
		Exceptions.h \
		Utils.h \

CommentSensivitiyList = \
		Comment.cpp \
		Comment.h \

UTflixSensivityList = \
		UTflix.cpp \
		UTflix.h \
		Publisher.h \
		

all: UTflix.out 



main.o: $(mainSensitivityList)
	$(CC) -c main.cpp


Utils.o: $(UtilsSensitivityList)
	$(CC) -c  Utils.cpp

md5.o: $(md5SensivityList)
	$(CC) -c  md5.cpp

Exceptions.o: $(ExceptionsSensivityList)
	$(CC) -c  Exceptions.cpp

RequestReciever.o: $(RequestRecieverSensitivityList)
	$(CC) -c  RequestReciever.cpp

Request.o: $(RequestSensivityList)
	$(CC) -c  Request.cpp

Response.o: $(ResponseSensivityList)
	$(CC) -c  Response.cpp

DataBase.o: $(DataBaseSensivityList)
	$(CC) -c  DataBase.cpp

UserSessionManagement.o: $(UserSessionManagementSensivityList)
	$(CC) -c  UserSessionManagement.cpp

Controller.o: $(ControllerSensivityList)
	$(CC) -c  Controller.cpp

ControllerManager.o: $(ControllerManagerSensivityList)
	$(CC) -c  ControllerManager.cpp

SignupController.o: $(SignupControllerSensivityList)
	$(CC) -c  SignupController.cpp

LoginController.o: $(LoginControllerSensivityList)
	$(CC) -c  LoginController.cpp

FilmController.o: $(FilmControllerSensivityList)
	$(CC) -c FilmController.cpp

FollowerController.o: $(FollowerController)
	$(CC) -c FollowerController.cpp

MoneyController.o: $(MoneyControllerSensivityList)
	$(CC) -c MoneyController.cpp

BuyController.o: $(BuyControllerSensivityList)
	$(CC) -c BuyController.cpp

RateController.o: $(RateControllerSensivityList)
	$(CC) -c RateController.cpp

RepliesController.o: $(RepliesControllerSensivityList)
	$(CC) -c RepliesController.cpp

CommentsController.o: $(CommentsControllerSensivityList)
	$(CC) -c CommentsController.cpp

PublishedController.o: $(PublishedControllerSensivityList)
	$(CC) -c PublishedController.cpp

FilmFilterController.o: $(FilmFilterControllerSensivityList)
	$(CC) -c FilmFilterController.cpp

PurchasedController.o: $(PurchasedControllerSensivityList)
	$(CC) -c PurchasedController.cpp

NotificationsController.o: $(NotificationsSensivityList)
	$(CC) -c NotificationsController.cpp

NotificationsReadController.o: $(NotificationsReadControllerSensivityList)
	$(CC) -c NotificationsReadController.cpp


UserService.o: $(UserServiceSensivityList)
	$(CC) -c  UserService.cpp

FilmService.o: $(FilmServiceSensivityList)
	$(CC) -c FilmService.cpp

FilmFilterService.o: $(FilmFilterServiceSensivityList)
	$(CC) -c FilmFilterService.cpp

User.o: $(UserSensivityList)
	$(CC) -c  User.cpp

Client.o: $(ClientSensivityList)
	$(CC) -c  Client.cpp

Publisher.o: $(PublisherSensivityList)
	$(CC) -c  Publisher.cpp

Film.o: $(FilmSensivityList)
	$(CC) -c  Film.cpp

Comment.o: $(CommentSensivitiyList)
	$(CC) -c  Comment.cpp

UTflix.o: $(UTflixSensivityList)
	$(CC) -c UTflix.cpp

UTflix.out: $(OBJECTS)
	$(CC) -o UTflix.out $(OBJECTS)

.PHONY: clean

clean:
	rm *.o
	rm UTflix.out