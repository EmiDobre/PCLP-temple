TASK 1:

-sparg inputul de coduri pt a afla codurile efective ce urmeaza a fi decodate 
-pt fiecare tip de cod=> fct care intoarce un nr intreg 
-am codificat rezultatul intors de fct drep : -1-jos, 0-sus, 2-dreapta, 1-stanga
-fiecare cod mic reprezint o directie in matrice=> directia este reprezentata de vectorul drum 
-drum[pasi] va arata la pasul x in ce directie o ia de ex: drum[2]=0=> la pasul 2 directia de mers este sus
-dupa decodificare vectorul drum ar arata ceva de genul: 0 1 -1 0 0 1 2 2 etc 
-aloc dinamic matricea cu calloc pt a se initializa automat cu 0
-pasul 1 din matrice este mereu matrix[0][0]=1, pronesc de la 2 pana la cati pasi am pt a realiza drumul in matrice



TASK 2:

-in functie de stringul introdus se apeleaza o fct care decodeaza pt caesar/vigenere/addition cu strcmp
    1)CAESAR:
    -se apeleaza fct caesar care modifica codul primit ca parametru prin cheie
    -in fct de tipul de caracter am facut un for pt a merge cu i pozitii inapoi pana se atinge nr introdus ca si cheie

    2)VIGENERE:
    -fct modifica codul primit ca parametru prin cheie
    -vectorul rotire arata pt fiecare caracter din cod cheia numerica cu care se decripteaza tot dupa algoritmul de la caesar
    -astfel "decodez" cheia(scad 65 pt ca sunt doar lit mari)
    -la fel ca la caesar se decodeaza dupa rotire[i] fiecare caracter
    
    3)ADDITION:
    -fct primeste ca parametru cele 2 coduri deja decodate cu caesar
    Pasi:
    1.-verific daca sirurile de caractere au acc lungime, daca nu le aduc la aceeasi lungime adaugand la sirul mai mic 0-uri in fata, ex: 0002 cu 6896
      -apelez functia lungime_noua unde am alocat dinamic noul sir pt a-l putea folosi in functia addition

    2.inversez sirurile pt a le aduna mai usor si a lucra cu pozitiile caracterelor mai simplu, astfel apelez functia reversed care intoarce un pointer deja alocat 

    3.-fac suma pe "bucati"(pozitii) dintre numerele reversed care au deja acc lungime
     -plus reprezinta "ce tinem minte" cand adunam si depaseste de 10, care prima data este 0
     -daca valoare sume[i] depaseste 57 inseamna -48 din suma  depaseste valoare 10=> plus va deveni acum 1
     -daca la sfarsitul forului plus este 1=> se mai adauga o pozitie in sir ( 99+02=>101), altfel ramane cum este
     -suma reala se afla prin apelarea fct reversed
     -in cazul in care suma incepe cu 0=> le elimin
     -addition intoarce in final suma ceruta


TASK 3:

-citesc cu un while fgets mai multe stringuri pana ce se introduce de la tastatura de 2 ori enter astfel citesc toate textele input
-textul este stocat drept mai multe stringuri care au fost delimitate de un \n
-verific daca exista stringuri "goale" care au doar white spaces- le sterg
-stringurile obtinute le "lipesc" intr-un string text care contine practic inputul fara enter
-impart in cuvinte cu strtok in functie de separatori si obtin o matrice de cuvinte, un string de cuvinte si aflu si numarul lor
-secventele cautate le obtin prin contopirea a cate 2 cuvinte separate apoi prin spatiu -- prin memcpy
-obtin un nr de  nr_cuv-1 printre care sunt dupplicate cateva => le sterg

-pentru a gasi duplicatele trec prin toate secventele 
-verific in ordine daca am copii ale acelei secvente prin j care vf daca pana in secventa i am o secventa identica
-daca fac ca secventa dubla sa devina stringul null si ies din conditie pt ca am gasit unde se repeta
-daca nu am gasit nicio duplicatie atunci copiez secventa[i] in secventa_ofc[k] marind k-ul pt a numara cate secvente neduplicate am

-aparitiile fiecarei secvente le salvez intr-un vector initializat cu 0 din calloc 
-verific pt fiecare secventa_ofc de cate ori este gasita in matricea de secventa initiala salvata cu copie

