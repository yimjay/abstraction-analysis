
Stack: { top elem ... } with
{
  Pop: { top elem1 elem ...} -> elem1 * { top elem ...};
  Push: { top elem ... } * elem1 -> { top elem1 elem ...};
  Empty : { top } -> true;
        { top elem1 elem ...} -> false;
};

Queue: { front elem ... back } with
{
  Pop: {front elem1 elem ... back} -> elem1 * {front elem ... back};
  Push: {front elem ... back} * elem1 -> {front elem ... elem2 back}; 
  Empty : { front back} -> true;
          { front elem1 elem ... back} -> false;
};

