Queue: { front elem ... back } with
{
  Pop: {front elem1 elem ... back} -> {front elem ... back} * elem1;
  Push: {front elem ... back} * elem1 -> {front elem ... elem2 back}; 
  Empty : { front back } -> { front back } * true;
          { front elem1 elem ... back } -> { front elem1 elem ... back } * false;
};