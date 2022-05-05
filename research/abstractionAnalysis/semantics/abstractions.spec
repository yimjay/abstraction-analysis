Stack: { top elem ... } with
{
  Pop: { top elem1 elem ...} -> { top elem ...} * elem1;
  Push: { top elem ... } * elem1 -> { top elem1 elem ...};
  Empty : { top } -> { top } * true;
        { top elem1 elem ...} -> { top elem1 elem ...} * false;
};

