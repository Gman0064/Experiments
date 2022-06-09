with Ada.Containers.Indefinite_Vectors;
with Ada.Containers.Vectors;

package body Util is
    function Remove_Duplicates(Nums : out Int_Vec.Vector) return Integer is
        I   : Integer := 1;
    begin
        for J in Nums.First_Index .. Nums.Last_Index loop
            if (Nums(J) /= Nums(I)) then
                I := I + 1;
                Nums.Replace_Element(I, Nums(J));
            end if;
        end loop;
        return I;
    end Remove_Duplicates;
end Util;
