echo "enter 'player' for player vs player or enter 'computer' for computer vs player"

read -t 5 choice 

if [[$choice == "player"]]; then 
	sleep 2 && mqttx pub -t 'esp32/tictac' -h 'broker.emqx.io' -p 1883 -m "p"

else if [[$choice == "computer"]] then 
    sleep 2 && mqttx pub -t 'esp32/tictac' -h 'broker.emqx.io' -p 1883 -m "a" &
else 
    echo "the choice you have made is invalid you will automatically be set to play against a computer"