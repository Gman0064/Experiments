with Ada.Containers.Indefinite_Vectors;
with Ada.Containers.Vectors;

package Util is
    package Int_Vec is new Ada.Containers.Indefinite_Vectors
            (Index_Type   => Positive,
            Element_Type => Integer);

    use type Int_Vec.Vector;

    function Remove_Duplicates(Nums : out Int_Vec.Vector) return Integer;
end Util;