<p align=center>
    <a href="https://github.com/YunruKnowledge/Test-Project-CI-GTest-Example/actions/workflows/requirement-test.yml">
        <img src="https://github.com/YunruKnowledge/Test-Project-CI-GTest-Example/actions/workflows/requirement-test.yml/badge.svg">
    </a>
</p>

<h1 align=center>Requirements:</h1>

## Using `TDD` and `googletest` develop and test a `template` queue `class` implemented using a linked list according the following requirements.

- The class shall be uncopayable and moveable.
- To build and run the test, use a cmake file.
- Ensure that the dynamically allocated memory blocks are released
- The class shall provide the following functions:
    - An enqueue function to enqueue a data element to a queue.
    - A size function to return the number of data elements stored in a queue.
    - A dequeue function to dequeue a data element from the queue
    - A clear function to clear a queue.
- The class shall be tested with types: `int`, `float` and `std::string`
- Don’t use `std::exit` or `assert` in the `class`.

## Practice CI by:

- Following the `Github Flow` strategy
- Creating a workflow which is triggered on
    - `Push` to any branch to build and run the test
    - `Pull` request to the main branch to build and run the test
- Creating a status badge in README.md
