echo "Enter a number"
read n
for (( i=1;i<=n;i++ ))
do
for (( j=i;j<=n;j++ ))
do echo -n " $j"
done
echo
done
