open Js.Promise;
open Jest;
open Expect;
open ReactTestingLibrary;

describe("Login component", () => {
  testPromise("renders without crashing", () => {
    let wrapper = render(<App />);

    TestUtils.act(() => ReasonReactRouter.push("#/login"));

    DomTestingLibrary.waitForElement(
      ~callback=
        () => wrapper |> getByText(~matcher=`Str("Need an account?")),
      (),
    )
    |> then_(_ =>
         wrapper
         |> getByText(~matcher=`Str("Need an account?"))
         |> Webapi.Dom.Element.innerHTML
         |> expect
         |> toEqual("Need an account?")
         |> resolve
       );
  });

  // TODO: delete following line when we have more than 1 test case
  let _ = ();
});
