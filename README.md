# MarketSimulationServer
To compile: "g++ responce.cpp main.cpp netConnect.cpp -lboost_system -lpthread -std=c++0x"

Make sure to install the Boost library

## General Notes on market database



1. market.maintenance

last_update - last time a game update was applied

next_update - next scheduled game update (should update automatically)

clicks - number of updates "clicks"

word_of_the_day - for possible game mechanic

2. market.users_tbl

uuid - unique user id (should increment automatically)

liquid_assets - liquid assets available to the user

portfolio - text with space separated values. first number is the uuid of a company, second is percentage that the user will receive when 
it gets a shipment <-- seems fine

3. market.corps_tbl

uuid - unique corporatoin id (should increment automatically)

liquid_assets - liquid assets available to corp

futures - text with space separated values. first number is the uuid of a user, second is percentage that user will receive when this corp makes a shipment <-- seems fine

modifiers - text with space separated values. first number is the name of modifier, second is the value

postings - offers on the futures that users have placed on this company. text separated values with uuid followed by percentage
