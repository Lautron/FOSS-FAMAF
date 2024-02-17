# open new alacritty instance, change dir to back and run make run
alacritty -e sh -c "cd back && make run" &
alacritty -e sh -c "cd LaCosaFront && npm run dev" &
