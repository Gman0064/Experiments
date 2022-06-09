with Ada.Text_IO;   use Ada.Text_IO;
with Util;          use Util;

procedure Main is
    Nums : Int_Vec.Vector;
begin
    Nums.Append(1);
    Nums.Append(1);
    Nums.Append(2);
    Nums.Append(3);

    Put_Line (Util.Remove_Duplicates(Nums)'Image);
end Main;
