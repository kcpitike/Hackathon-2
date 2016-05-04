
[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 2
  ny = 2
  nz = 2

  xmin = -300
  xmax = 300

  ymin = -300
  ymax = 300

  zmin = -300
  zmax = 300

[]

[GlobalParams]
  U = U
  Phi = Phi
  disp_x = disp_x
  disp_y = disp_y
  disp_z = disp_z
  k = 3
  h0 = 0.24
[]

[Variables]
    [./Phi]
        order = FIRST
        family = LAGRANGE
        [./InitialCondition]
            type = SmoothCircleIC
            x1 = 0.0
            y1 = 0.0
            z1 = 0.0
            radius = 100.089
            invalue = 1.0
            int_width = 1.0
            outvalue = 0.0
        [../]
    [../]
#    [./disp_x]
#        order = THIRD
#        family = HERMITE
#        [./InitialCondition]
#            type = RandomIC
#            min = -1e-4
#            max = 1e-4
#        [../]
#    [../]
#    [./disp_y]
#        order = THIRD
#        family = HERMITE
#        [./InitialCondition]
#            type = RandomIC
#            min = -1e-4
#            max = 1e-4
#        [../]
#    [../]
#    [./disp_z]
#        order = THIRD
#        family = HERMITE
#        [./InitialCondition]
#            type = RandomIC
#            min = -1e-4
#            max = 1e-4
#        [../]
#    [../]
[]


[Kernels]
    #Elastic problem
#[./TensorMechanics]
        #This is an action block
#    [../]
    [./dt_Phi]
        type = TimeDerivative
        variable = Phi
    [../]
#    [./E1]
#        type = ElasticEnergy
#        variable = Phi
#    [../]
    [./E2]
        type = PhaseGrad
        variable = Phi
    [../]
    [./E3]
        type = DoubleWell
        variable = Phi
    [../]
[]


[BCs]
#  [./zero_displacement_x]
#    type = DirichletBC
#    variable = disp_x
#    value = 0.0
#    boundary = 'front back top bottom left right'
#  [../]
#    [./zero_displacement_y]
#        type = DirichletBC
#        variable = disp_y
#        value = 0.0
#        boundary = 'front back top bottom left right'
#    [../]
#    [./zero_displacement_z]
#        type = DirichletBC
#        variable = disp_z
#        value = 0.0
#        boundary = 'front back top bottom left right'
#    [../]
  [./vacuum_boundary]
    type = DirichletBC
    variable = Phi
    value = 0
    boundary = 'front back top bottom left right'
  [../]
[]

[Materials]
    [./elasticity_tensor_2]
        type = ComputeElasticityTensor
        C_ijkl = '233.4 144.5 116.3 289 81.4 380.1 99.5 87.8 112.3'
        fill_method = symmetric9
    [../]
[]

[Preconditioning]
  [./smp]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_gmres_restart  -snes_rtol -ksp_rtol -pc_type '
    petsc_options_value = '    500                1e-8     1e-8      hypre   '
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
  #scheme = 'rk-2'   #"implicit-euler, explicit-euler, crank-nicolson, bdf2, rk-2"
  #dt = 0.5
  dtmin = 1e-28
  dt  = 0.5e-4
  dtmax = 10
[]

[Outputs]
  print_linear_residuals = true
  print_perf_log = true
  [./out]
    type = Exodus
    file_base = out_prob2_test_test
    elemental_as_nodal = true
    interval = 1
  [../]
[]
