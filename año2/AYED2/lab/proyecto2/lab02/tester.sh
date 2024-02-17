  
for folder in ej1 ej2 ej3 ej4; do
  for filename in input/*.in ; do
    string="./$folder/sorter $filename > /dev/null && echo '$folder $filename works' || echo '$folder/$filename FAILED'" 
    echo $string
    echo ""
    eval $string
  done
done

