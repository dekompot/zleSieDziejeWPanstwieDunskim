module type Numerical_type = sig
  type num_type
  val to_float : num_type -> float
end;;

module Int_Type : Numerical_type =
struct
  type num_type = int
  let to_float x = float_of_int(x) 
end;;

module type Point =
sig
  type t
  val distance: t * t -> float
end;;

module Point_Implementation (N: Numerical_type) : Point = 
struct
  type t = {x:N.num_type; y:N.num_type; z:N.num_type}
  let distance ((m:t),(n:t)) = sqrt((N.to_float(m.x) -. N.to_float(n.x))**2. 
  +. (N.to_float(m.y) -. N.to_float(n.y))**2. +. (N.to_float(m.z) -. N.to_float(n.z))**2.)
end;;

module Point_Int = Point_Implementation(Int_Type);;       