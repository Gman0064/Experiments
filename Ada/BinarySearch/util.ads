with Ada.Containers.Vectors;
with Ada.Containers.Indefinite_Vectors;

package Util is
    package Int_Vec is new Ada.Containers.Indefinite_Vectors
            (Index_Type   => Positive,
            Element_Type => Integer);

    use type Int_Vec.Vector;
end Util;