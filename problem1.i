
[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  ymax = 40
  ymin = -40
  xmin = -40
  xmax = 40
[]

[GlobalParams]
  U = U
  Phi = Phi
  PhiWdx = PhiWdx
  PhiWdy = PhiWdy
  D = 10.0
  W0 = 1.0
  t0 = 1.0
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
      x1 = 25.0
      y1 = 25.0
      radius = 2.0
      value = 1.0
    [../]
  [../]
  [./PhiWdx]
    order = FIRST
    family = LAGRANGE
  [../]
  [./PhiWdy]
    order = FIRST
    family = LAGRANGE
  [../]
[]


[AuxVariables]
  [./temp]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]


[AuxKernels]
  [./tempfield]
    type = TempField
    variable = temp
  [../]
[]


[Kernels]
  [./dt_U]
    type = TimeDerivative
    variable = U
  [../]
  [./solid1]
    type = Solidification1
    variable = U
  [../]
  [./solid2]
    type = Solidification2
    variable = Phi
  [../]
  [./solid3]
    type = Solidification3
    variable = Phi
  [../]
  [./solid4]
    type = Solidification4dxdy
    variable = Phi
  [../]
  [./solidXsplit]
    type = XSplitSolidification
    variable = PhiWdx
  [../]
  [./solidYsplit]
    type = YSplitSolidification
    variable = PhiYdx
  [../]
[]


[BCs]
  [./potential_int_top]
    type = DirichletBC
    variable = U
    value = -1.0
    boundary = 'top bottom left right'
  [../]
[]


[Preconditioning]
  [./smp]
    type = SMP
    full = true
    #petsc_options = '-snes_view -snes_linesearch_monitor -snes_converged_reason -ksp_converged_reason'
    #petsc_options_iname = '-ksp_gmres_restart  -snes_rtol -ksp_rtol -pc_type'
    #petsc_options_value = '    121                1e-6      1e-8    bjacobi'
  [../]
[]

[Executioner]
  type = Transient
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
  scheme = 'implicit-euler'   #"implicit-euler, explicit-euler, crank-nicolson, bdf2, rk-2"
  #dt = 0.5
  dtmin = 1e-13
  dtmax = 0.05
[]

[Outputs]
  print_linear_residuals = true
  print_perf_log = true
  [./out]
    type = Exodus
    file_base = out_prob1_test
    elemental_as_nodal = true
    interval = 1
  [../]
[]