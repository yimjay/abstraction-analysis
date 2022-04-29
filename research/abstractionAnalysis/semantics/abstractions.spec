
Stack: { top elem ... } with
{
  Pop: { top elem1 elem ...} -> { top elem ...} * elem1;
  Push: { top elem ... } * elem1 -> { top elem1 elem ...};
  Empty : { top } -> { top } * true;
        { top elem1 elem ...} -> { top elem1 elem ...} * false;
};

Queue: { front elem ... back } with
{
  Pop: {front elem1 elem ... back} -> {front elem ... back} * elem1;
  Push: {front elem ... back} * elem1 -> {front elem ... elem2 back}; 
  Empty : { front back } -> { front back } * true;
          { front elem1 elem ... back } -> { front elem1 elem ... back } * false;
};

