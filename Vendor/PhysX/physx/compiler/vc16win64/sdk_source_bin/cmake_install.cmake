# Install script for directory: D:/Playground/FunShot/Vendor/PhysX/physx/source/compiler/cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PhysX")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/source/foundation/include/windows" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/windows/PsWindowsAoS.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/windows/PsWindowsFPU.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/windows/PsWindowsInclude.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/windows/PsWindowsInlineAoS.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/windows/PsWindowsIntrinsics.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/windows/PsWindowsTrigConstants.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/windows/PxWindowsIntrinsics.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/windows" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/windows/PxWindowsIntrinsics.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/unix/PxUnixIntrinsics.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/unix" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/unix/PxUnixIntrinsics.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXFoundation_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXFoundation_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXFoundation_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXFoundation_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxFoundation.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/foundation" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/foundation/PxAssert.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/foundation/PxFoundationConfig.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/foundation/PxMathUtils.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/source/foundation/include" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/Ps.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsAlignedMalloc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsAlloca.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsAllocator.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsAoS.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsArray.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsAtomic.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsBasicTemplates.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsBitUtils.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsBroadcast.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsCpu.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsFoundation.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsFPU.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsHash.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsHashInternals.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsHashMap.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsHashSet.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsInlineAllocator.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsInlineAoS.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsInlineArray.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsIntrinsics.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsMathUtils.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsMutex.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsPool.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsSList.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsSocket.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsSort.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsSortInternals.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsString.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsSync.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsTempAllocator.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsThread.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsTime.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsUserAllocated.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsUtilities.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecMath.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecMathAoSScalar.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecMathAoSScalarInline.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecMathSSE.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecMathUtilities.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecQuat.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/source/foundation/include/PsVecTransform.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/Px.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxAllocatorCallback.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxProfiler.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxSharedAssert.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxBitAndData.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxBounds3.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxErrorCallback.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxErrors.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxFlags.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxIntrinsics.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxIO.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMat33.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMat44.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMath.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMemory.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxPlane.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxPreprocessor.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxQuat.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxSimpleTypes.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxStrideIterator.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxTransform.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxUnionCast.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxVec2.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxVec3.h;D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxVec4.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Playground/FunShot/Vendor/PhysX/physx/install/vc15win64/PxShared/include/foundation" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/Px.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxAllocatorCallback.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxProfiler.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxSharedAssert.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxBitAndData.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxBounds3.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxErrorCallback.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxErrors.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxFlags.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxIntrinsics.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxIO.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxMat33.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxMat44.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxMath.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxMemory.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxPlane.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxPreprocessor.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxQuat.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxSimpleTypes.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxStrideIterator.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxTransform.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxUnionCast.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxVec2.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxVec3.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/../pxshared/include/foundation/PxVec4.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gpu" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/gpu/PxGpu.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cudamanager" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cudamanager/PxCudaContextManager.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cudamanager/PxCudaMemoryManager.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/common/windows" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/windows/PxWindowsDelayLoadHook.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysX_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysX_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysX_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysX_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxActor.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxAggregate.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxArticulationReducedCoordinate.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxArticulationBase.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxArticulation.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxArticulationJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxArticulationJointReducedCoordinate.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxArticulationLink.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxBatchQuery.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxBatchQueryDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxBroadPhase.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxClient.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxConstraint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxConstraintDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxContact.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxContactModifyCallback.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxDeletionListener.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxFiltering.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxForceMode.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxImmediateMode.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxLockedData.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxMaterial.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxPhysics.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxPhysicsAPI.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxPhysicsSerialization.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxPhysicsVersion.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxPhysXConfig.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxPruningStructure.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxQueryFiltering.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxQueryReport.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxRigidActor.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxRigidBody.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxRigidDynamic.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxRigidStatic.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxScene.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxSceneDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxSceneLock.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxShape.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxSimulationEventCallback.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxSimulationStatistics.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxVisualizationParameter.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/common" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxBase.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxCollection.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxCoreUtilityTypes.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxMetaData.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxMetaDataFlags.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxPhysicsInsertionCallback.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxPhysXCommonConfig.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxRenderBuffer.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxSerialFramework.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxSerializer.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxStringTable.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxTolerancesScale.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxTypeInfo.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/common/PxProfileZone.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pvd" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/pvd/PxPvdSceneClient.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/pvd/PxPvd.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/pvd/PxPvdTransport.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/collision" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/collision/PxCollisionDefs.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/solver" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/solver/PxSolverDefs.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/PxConfig.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCharacterKinematic_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCharacterKinematic_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCharacterKinematic_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCharacterKinematic_static_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/characterkinematic" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxBoxController.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxCapsuleController.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxController.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxControllerBehavior.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxControllerManager.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxControllerObstacles.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/characterkinematic/PxExtended.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCommon_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCommon_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCommon_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCommon_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/geometry" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxBoxGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxCapsuleGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxConvexMesh.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxConvexMeshGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxGeometryHelpers.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxGeometryQuery.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxHeightField.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxHeightFieldDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxHeightFieldFlag.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxHeightFieldGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxHeightFieldSample.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxMeshQuery.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxMeshScale.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxPlaneGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxSimpleTriangleMesh.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxSphereGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxTriangle.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxTriangleMesh.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxTriangleMeshGeometry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geometry/PxBVHStructure.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/geomutils" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geomutils/GuContactBuffer.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/geomutils/GuContactPoint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCooking_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCooking_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCooking_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCooking_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cooking" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxBVH33MidphaseDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxBVH34MidphaseDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/Pxc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxConvexMeshDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxCooking.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxMidphaseDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxTriangleMeshDesc.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/cooking/PxBVHStructureDesc.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXExtensions_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXExtensions_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXExtensions_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXExtensions_static_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/extensions" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxBinaryConverter.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxBroadPhaseExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxCollectionExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxConstraintExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxContactJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxConvexMeshExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxD6Joint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxD6JointCreate.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxDefaultAllocator.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxDefaultCpuDispatcher.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxDefaultErrorCallback.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxDefaultSimulationFilterShader.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxDefaultStreams.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxDistanceJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxContactJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxExtensionsAPI.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxFixedJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxJointLimit.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxMassProperties.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxPrismaticJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxRaycastCCD.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxRepXSerializer.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxRepXSimpleType.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxRevoluteJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxRigidActorExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxRigidBodyExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxSceneQueryExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxSerialization.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxShapeExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxSimpleFactory.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxSmoothNormals.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxSphericalJoint.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxStringTableExt.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/extensions/PxTriangleMeshExt.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/filebuf" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/include/filebuf/PxFileBuf.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXVehicle_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXVehicle_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXVehicle_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXVehicle_static_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vehicle" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleComponents.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleDrive.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleDrive4W.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleDriveNW.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleDriveTank.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleNoDrive.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleSDK.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleShaders.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleTireFriction.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleUpdate.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleUtil.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleUtilControl.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleUtilSetup.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleUtilTelemetry.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/vehicle/PxVehicleWheels.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/source/fastxml/include" TYPE FILE FILES "D:/Playground/FunShot/Vendor/PhysX/physx/source/fastxml/include/PsFastXml.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXPvdSDK_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXPvdSDK_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXPvdSDK_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXPvdSDK_static_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXTask_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXTask_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXTask_static_64.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE FILE OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXTask_static_64.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/task" TYPE FILE FILES
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/task/PxCpuDispatcher.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/task/PxTask.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/task/PxTaskDefine.h"
    "D:/Playground/FunShot/Vendor/PhysX/physx/include/task/PxTaskManager.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXFoundation_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXFoundation_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXFoundation_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXFoundation_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXFoundation_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXFoundation_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXFoundation_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXFoundation_64.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXFoundation.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXFoundation.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXFoundation.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXFoundation.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysX_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysX_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysX_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysX_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysX_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysX_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysX_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysX_64.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysX.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysX.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysX.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysX.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCharacterKinematic_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCharacterKinematic_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCharacterKinematic_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCharacterKinematic_static_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCharacterKinematic.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCharacterKinematic.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCharacterKinematic.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCharacterKinematic.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXPvdSDK_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXPvdSDK_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXPvdSDK_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXPvdSDK_static_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXPvdSDK.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXPvdSDK.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXPvdSDK.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXPvdSDK.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCommon_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCommon_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCommon_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCommon_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCommon_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCommon_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCommon_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCommon_64.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCommon.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCommon.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCommon.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCommon.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCooking_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCooking_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCooking_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCooking_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCooking_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXCooking_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXCooking_64.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE SHARED_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXCooking_64.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCooking.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCooking.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCooking.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXCooking.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXExtensions_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXExtensions_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXExtensions_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXExtensions_static_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXExtensions.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXExtensions.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXExtensions.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXExtensions.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXVehicle_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXVehicle_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXVehicle_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXVehicle_static_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXVehicle.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXVehicle.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXVehicle.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXVehicle.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/debug" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXTask_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/checked" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/checked/PhysXTask_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/profile" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/profile/PhysXTask_static_64.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.md/release" TYPE STATIC_LIBRARY FILES "D:/Playground/FunShot/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/release/PhysXTask_static_64.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXTask.dir/install-cxx-module-bmi-debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXTask.dir/install-cxx-module-bmi-checked.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXTask.dir/install-cxx-module-bmi-profile.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Playground/FunShot/Vendor/PhysX/physx/compiler/vc16win64/sdk_source_bin/CMakeFiles/PhysXTask.dir/install-cxx-module-bmi-release.cmake" OPTIONAL)
  endif()
endif()

