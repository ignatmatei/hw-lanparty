# hw-lanparty
ca sa rulezi :
1) make build in fisierul cu solutia
2) ./lanParty
3) in r.out vei avea generat raspunsul

Structuri de date :
Toate structurile le am organizat intr o substructura de data si una care face legatura cu urmatorul el din motive de eficienta in prelucrarea datelor.
Solutie:
pentru a adauga la inceput fiecare element de tip team pe care il citesc am folosit functia de addAtBeginning din curs
am aflat cea mai mare putere a lui 2 <= nr de echipe si am tot scazut echipa cu puncatjul minim ramasa in lista pana cand noul numar e putere a lui 2
apoi am adaugat in structura de coada (in care un element retine datele a doua echipe) asa cum am gasit in lista  si dupa de fiecare data cand am scos din
lista un meci am adaugat o echipa in winnerstack si alta in loserstack. in cazul special in care numarul de echipe care nu au fost eliminate este 8 am adaugat
toate echipele din toate meciurile intr un arbore bst(care pt nu a declara 2 structuri de date foarte similare pt bst si avl avea si un atribut height pe care nu
l-am folosit). in arborele bst pentru a afla de fiecare data valoarea maxima m -am dus cat de in dreapta am putut si dupa am sters acel nod.
pentru prelucrarea datelor din AVL am luat rotatiile din curs nu stiu cat de mult ar trebui sa explic.
De mentionat ca la fiecare pas am eliberat memoria aferenta. 

