
[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 50
  ny = 50
  ymax = 4
  ymin = -4
  xmin = -4
  xmax = 4
[]

[GlobalParams]
  U = U
  Phi = Phi
  PhiWdx = PhiWdx
  PhiWdy = PhiWdy
  D = 10.0
  W0 = 1.0
  tau0 = 1.0
  Eps_m = 0.025
  m = 4.0
  offset = 0.0000000001
  #Cp =
  #Tm =
  #L = 20.0
[]

[Variables]
  [./U]
    order = FIRST
    family = LAGRANGE
    [./InitialCondition]
      type = ConstantIC
      value = 1.0
    [../]
  [../]
  [./Phi]
    order = FIRST
    family = LAGRANGE
    [./InitialCondition]
      type = SmoothCircleIC
      x1 = 0.0
      y1 = 0.0
      radius = 2.1
      int_width = 0.5
      invalue = 1.0
      outvalue = -1.0
    [../]
  [../]
  #[./PhiWdx]
  #  order = FIRST
  #  family = LAGRANGE
  #[../]
  #[./PhiWdy]
  #  order = FIRST
  #  family = LAGRANGE
  #[../]
[]


[AuxVariables]
  #[./temp]
#    order = CONSTANT
#    family = MONOMIAL
#  [../]
[]


[AuxKernels]
#  [./tempfield]
#    type = TempField
#    variable = temp
#  [../]
[]


[Kernels]
  [./dt_U]
    type = TimeDerivative
    variable = U
  [../]

  [./dt_PHI]
    type = TimeDerivative
    variable = Phi
  [../]

  [./solid1]
    type = Solidification1
    variable = U
  [../]

  [./solid2u]
    type = Solidification2
    variable = U
  [../]


  [./solid3u]
    type = Solidification3
    variable = U
  [../]

  [./solid2p]
    type = Solidification2
    variable = Phi
  [../]


  [./solid3p]
    type = Solidification3
    variable = Phi
  [../]
  #[./solid4]
  #  type = Solidification4dxdy
  #  variable = Phi
  #[../]
  #[./solidXsplit]
  #  type = XSplitSolidification
  #  variable = PhiWdx
  #[../]
  #[./solidYsplit]
  #  type = YSplitSolidification
  #  variable = PhiWdy
  #[../]
[]

[Materials]

[]


[BCs]
  [./heat_boundary]
    type = DirichletBC
    variable = U
    value = 1.0
    boundary = 'top bottom left right'
  [../]
  [./liquid_boundary]
    type = DirichletBC
    variable = Phi
    value = -1.0
    boundary = 'top bottom left right'
  [../]

  #[./liquid_boundary1]
  #  type = DirichletBC
  #  variable = PhiWdx
  #  value = 0.0
  #  boundary = 'top bottom left right'
  #[../]
  #[./liquid_boundary2]
  #  type = DirichletBC
  #  variable = PhiWdy
  #  value = 0.0
  #  boundary = 'top bottom left right'
  #[../]
[]


[Adaptivity]
  marker = EFM_1
  initial_steps = 2
  max_h_level = 2
  [./Markers]
    [./EFM_1]
      type = ErrorFractionMarker
      coarsen = 0.2
      refine = 0.5
      indicator = GJI_1
    [../]
  [../]

  [./Indicators]
    [./GJI_1]
     type = GradientJumpIndicator
     variable = Phi
    [../]
  [../]
[]

[Postprocessors]
[./NL_iter]
  type = NumNonlinearIterations
 [../]
 [./L_evals]
  type = NumResidualEvaluations
 [../]
 [./nodes]
  type = NumNodes
 [../]
 [./numDOFs]
  type = NumDOFs
 [../]
[]


[Preconditioning]
  [./smp]
    type = SMP
    full = true
    petsc_options_iname = '-pc_type -snes_rtol -ksp_rtol'
    petsc_options_value = ' lu   1e-6    1e-6'

  [../]
[]

[Executioner]
  type = Transient
  petsc_options = '-snes_converged_reason -snes_monitor -ksp_converged_reason'
  #petsc_options_iname = '-snes_linesearch_type '
  #petsc_options_value = 'none'
#    [./TimeStepper]
#    type = IterationAdaptiveDT
#    dt = 0.2
#    #iteration_window = 3
#    optimal_iterations = 6 #should be 5 probably
#    growth_factor = 1.4
#    linear_iteration_ratio = 1000
#    cutback_factor =  0.75
#[../]
  solve_type = 'PJFNK'       #"PJFNK, JFNK, NEWTON"
  abort_on_solve_fail = true
  scheme = 'implicit-euler'   #"implicit-euler, explicit-euler, crank-nicolson, bdf2, rk-2"
  #dt = 0.5
  dtmin = 1e-28
  dt  = 1.0e-5
  dtmax = 10
[]

[Outputs]
  print_linear_residuals = true
  print_perf_log = true
  [./out]
    type = Exodus
    file_base = out_prob1_test_test_test4
    elemental_as_nodal = true
    interval = 1
  [../]
[]
