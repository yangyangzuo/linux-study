   function sum(){
        s=0;
        s=$[$1+$2]
        echo $s
    }
    read -p "input parameter1" p1
    read -p "input parameter2" p2
    sum $p1 $p2