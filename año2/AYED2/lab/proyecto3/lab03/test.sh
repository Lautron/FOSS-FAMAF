for infile in $2*.in; do
  echo $infile
  $1 $infile
done
