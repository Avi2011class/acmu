var a, b : longint;

begin
  assign(input, 'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);
  read(a, b);
  write(a + b);
end.