# Ej1
cat /proc/cpuinfo | grep -m 1 'model name'

# Ej2
cat /proc/cpuinfo | grep 'model name' | wc -l

# Ej3
wget -qO- 'https://www.gutenberg.org/files/11/11-0.txt' | sed 's/Alice/Lautaro/g' > LAUTARO_in_wonderland.txt

# Ej4
sort -nk5 weather_cordoba.in | head -n 1 | grep -Eo '^[0-9]{4} [0-9]{1,2} [0-9]{1,2}'
sort -nk5 weather_cordoba.in | tail -n 1 | grep -Eo '^[0-9]{4} [0-9]{1,2} [0-9]{1,2}'

# Ej5
sort -nk3 atpplayers.in

# Ej6
awk '{print $0, $7-$8 | "sort -nk2,2 -nk9,9"}' superliga.in | awk '{NF--; print}'

# Ej7
ip link show | grep -oPm1 'ether \K(\w|:)+'

# Ej8a
mkdir Rick_and_Morty && cd Rick_and_Morty && for i in {01..10}; do touch "fma_S01E${i}_es.srt"; done

# Ej8b
for chapter in *.srt; do mv "$chapter" ${chapter/_es/}; done && cd ..



