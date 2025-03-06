echo "Enter number"
read n
for ((i=1;i<11;i++))
do
prod=$(( n*i ))
echo -n "$n * $i = $prod"
echo
done
