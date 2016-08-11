Type Long = record
     Bytes : Array[0..1000] of Integer;
     Len : Integer;
End;

     Procedure FromString(var a :long; s :String); Var i :integer;  //&#209;&#238;&#231;&#228;&#224;&#237;&#232;&#229; &#232;&#231; &#241;&#242;&#240;&#238;&#234;&#232;
     Begin a.Len := Length(s) - 1; For i := 0 To a.Len Do a.Bytes[a.Len - i] := Ord(s[i + 1]) - 48; End;
     
     Function ToString(var a :long) :String; //&#207;&#240;&#229;&#238;&#225;&#240;&#224;&#231;&#238;&#226;&#224;&#237;&#232;&#229; &#226; &#241;&#242;&#240;&#238;&#234;&#243;
     Var Res :String;
     Var i :Integer;
     Begin
          Res := '';
          For i := 0 To a.Len Do Res := Res + chr(a.Bytes[a.Len - i] + 48);
          while res[1] = '0' do delete(res, 1, 1);
          ToString := Res;
     End;
     
     Procedure Add(var a:Long; var b:long); //&#196;&#238;&#225;&#224;&#226;&#235;&#229;&#237;&#232;&#229;
     var i, j :integer;
     var ResLen :integer;
     Begin
          If a.Len > b.Len Then ResLen := a.Len Else ResLen := b.Len;
          For i := 0 To ResLen Do a.Bytes[i] := a.Bytes[i] + b.Bytes[i];
          For i := 0 To ResLen Do
              If a.Bytes[i] > 9 Then
                 Begin
                      Inc(a.Bytes[i + 1]);
                      a.Bytes[i] := a.Bytes[i] mod 10;
                 End;
          If a.Bytes[ResLen + 1] > 0 Then Inc(ResLen);
          a.Len := ResLen;
     End;




var a, b :long;
var i, k, n, j :integer;
var v :array[0..1000] of long;


function min(a, b:integer) : integer;
begin
     if a > b then min := b else min := a;
end;

begin
     readln(k, n);
     for i := 0 to n do FromString(v[i], '0');
     FromString(v[0], '01');
     for i := 1 to n do
         for j := 1 to min(k, i) do
             Add(v[i], v[i - j]);
     writeln(ToString(v[n]));
end.
